// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "MenuHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "Interfaces/OnlineIdentityInterface.h"
#include "Engine/LocalPlayer.h"
#include "OnlineSubsystem.h"
#include "HttpModule.h"
#include "Interfaces/IHttpResponse.h"

namespace {
void ConnectViaLoginFlowImpl(UObject* WorldContextObject, APlayerController* PlayerController, FString AuthToken)
{
	// Send request to obtain PIT and LT using online subsystem auth token.
	TSharedRef<IHttpRequest> LoginTokenRequest = FHttpModule::Get().CreateRequest();
	LoginTokenRequest->SetVerb(TEXT("GET"));
	LoginTokenRequest->SetURL("https://xbl.actionoverfear.net:443/auth");
	LoginTokenRequest->SetHeader(TEXT("User-Agent"), TEXT("X-UnrealEngine-Agent"));
	LoginTokenRequest->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
	LoginTokenRequest->SetHeader(TEXT("Accepts"), TEXT("application/json"));
	LoginTokenRequest->SetHeader(TEXT("Authorization"), *AuthToken);
	LoginTokenRequest->OnProcessRequestComplete().BindLambda([WorldContextObject, PlayerController, AuthToken](FHttpRequestPtr Request, FHttpResponsePtr Response, bool bConnectedSuccessfully) {
		if (bConnectedSuccessfully)
		{
			UE_LOG(LogTemp, Warning, TEXT("Received response code %d with payload %s."), Response->GetResponseCode(), *Response->GetContentAsString());

			TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject());
			TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(Response->GetContentAsString());
			FJsonSerializer::Deserialize(JsonReader, JsonObject);

			FString PlayerIdentityToken = JsonObject->GetStringField("pit");
			FString LoginToken = JsonObject->GetStringField("lt");
			if (PlayerIdentityToken.Len() == 0)
			{
				UE_LOG(LogTemp, Warning, TEXT("Received empty PIT."));
				GEngine->AddOnScreenDebugMessage(-1, 200.0f, FColor::Red, TEXT("Failed to login. Received empty PIT."));
				return;
			}
			if (LoginToken.Len() == 0)
			{
				UE_LOG(LogTemp, Warning, TEXT("Received empty LT."));
				GEngine->AddOnScreenDebugMessage(-1, 200.0f, FColor::Red, TEXT("Failed to login. Received empty LT."));
				return;
			}

			// We can client travel now that we have a PIT and LT.
			FURL URL;
			URL.Map = TEXT("ThirdPersonExampleMap");
			URL.Host = "locator.improbable.io"; // Host doesn't actually matter, it just forces UEngine::Browse to treat it as a remote host.
			URL.AddOption(TEXT("locatorv2"));
			URL.AddOption(*FString::Printf(TEXT("playeridentity=%s"), *PlayerIdentityToken));
			URL.AddOption(*FString::Printf(TEXT("login=%s"), *LoginToken));
			UE_LOG(LogTemp, Log, TEXT("Attempting to travel to: %s"), *URL.ToString());
			PlayerController->ClientTravel(URL.ToString(), ETravelType::TRAVEL_Absolute);
		}
		else
		{
			auto ErrorMessage = FString::Printf(TEXT("Failed to login. Connection to %s failed."), *Request->GetURL());
			GEngine->AddOnScreenDebugMessage(-1, 200.0f, FColor::Red, ErrorMessage);
			UE_LOG(LogTemp, Warning, TEXT("%s"), *ErrorMessage);
		}
	});
	LoginTokenRequest->ProcessRequest();
}
}

void UMenuHelpers::ConnectViaLoginFlow(UObject* WorldContextObject, ULocalPlayer* Player)
{
	APlayerController* PlayerController = Player->GetPlayerController(WorldContextObject->GetWorld());

#if PLATFORM_XBOXONE == 0
	UE_LOG(LogTemp, Warning, TEXT("Login via locator is only supported on Xbox One at the moment."));
	FString StrippedAuthToken = TEXT(R"""(eyJlbmMiOiJBMTI4Q0JDK0hTMjU2IiwiYWxnIjoiUlNBLU9BRVAiLCJjdHkiOiJKV1QiLCJ6aXAiOiJERUYiLCJ4NXQiOiJjRHJEMnN4RzJscEFWOWhVLWF1ckpTZm1McXcifQ.cMHpZTT7V6EONOF_kpZh_bUi3HO90IBZY5YTC5ehazXxZdSrAve0hPizkL2eW43AuoA6byWM6utMh6lxF77HxuPggdqKyHSHsL0nsNhH0niXKFcyCHJo6mlU3a0OADd_pHcJ-8-V94Iyi2aHKU5Ft0Wve7F31YbFZXmEm9NTiQJ7cWXHMDReC-vOc456dyvInOMttg4zDjVxJM0gdyXnTB12LXx9wDJqgrf6c7Z3onC6o3qSZql20XY-nKtHLyN8tBq2R2X3iHmC5krInyFQpnCXDH37p0eZmtH83xO-7gZMicPRMKOAXC-aU8JzIJIGPGTMPlfe4Li_D1E0Y5CVvA.NqX9xod31QKDQ4FKOgZfeA.K6idXH5T2fNOYuGEagc9RJLbf6pnSJfE9uRyuGB2uPSJo7unoy4KuUfh-am1kf7jbrNKweN6zHRqisOF4v6uJ0RdGXUlIAnbJrVYq-rSlKOZ113BuUm8_ddQCeEBMedv3Raq4Qg5w74Y5PnYnfGXOvSkSIYi_XePPWPN8mlMKGCGya_EwtfZ3DMfthso0CInuNxLfZiXIaHB3ExCQcU5hMC-sFRkvoeIecIu3VO9nYZ23b7kHltX8MDqqoVWD5CaLF0s00y7NpuWbyEvIDhmMAoQ1SFWgScEe3w1s3WmjnzwFxH0qPxiXACVLO-U7r7Bgf0QJxsmnuEYNJgzn-LAcRqnkmgGPrzUCmdowBXMQkxsU6tqRB5wzF_gd1dcok_P9MKFyP0QA-QL18qfgpbtXIvueuSocHUJ7CdXTThKV_TW7Bg6fOomkIUnW_zCwSkiTij30szIqhj_YvNSTIK3MY_QvXNiZHxOEnc0E60yy0QmyBUwxYgA59qGSdePRFMIB5u9-Ibd800rWTuI8NUxaqppVQAuNmCCvQGBjcOyV3781HmJvxZHVd9i7z5YDidHYo5FHgi3vVKQOPxlsRDfNOzHg_0yGTSwMiL-okd_AU9qXqaXk7ROa7IlxPf4gz5sEZIdqaTIMnmNwWuavaYglTLi9iYGxoktOAfG7ShMupYsDLJHzf9jaM8oNEAUOS9jwcSNFDb0_AxepGRbkzSsFLaT6rWcSIsLf64K_W9vhbrXYVvcJ8bR42ixbkFW1BiS0v3hXd-_zuwP9FsaUh_2lI9DjKEeyoknS2xkQjURwNpL4ngHKRDFwbLzDkUQgq4MCznWuB0juClTWPrzVNZA9ShnwLHH1IVZuAyS8o3d4OAGikr2MJiGtXzBUCSGSbCnsEFjlbcmV2IcnkNhDMDlRxAHMIN8-OE3hXlFM5qTKF3w7QzJQY4M4hhhJZDiQ2G-sDI3Tftt7yxFLHDIzEW174E6LI9m-oZ-1FSBz_fR6FJd61GyUtJNaEmzy2kCJPwvgovnJkZxyOAGVkjHt5jBP_3nML2gyXdBqxEEDvmDPW0dbkCimtqI9qRzqd2rZY2wfpYizqKphy9tFvld1-37kgJPjTY7S_jIjbap3DKRDYrZWrr6CpGp_ILiOemQ4BLURPkkeNb-jelEJJxSAipe_oiVPm9jZ-forP3zzQdCNlnB5tU-ErhHdNyNfvvP9-5DA-9yJFMHE-_kVl5kaIPvaqM7H_WJBmANeQWTAZ0osklokPJXSWW6hQCxVkGDJuwfiorawBCpgZLVO8xOXjM25fJs3NUZ72-Spp3yHqd2g1HWCQnhE2UqDchNAZ2-M3MWXV0GPj7lCdxaXIk63PJAaOQdwybvmWKfIoXc1dcUi4uZezXPLQg3W-IO64jP9mDGx35qt-_AlqDIVpXOeM1fLmD6lwFScAS7LXxq1NHosN857Nymonw9kW82icT8bg4KcxxzmWWVbtTmaxzVt-RNfYFo3TsDyREeQG_5BllZvqdHVWA0IrodRjhp8h0OHPvKgUQMr7opaV6Bty66a32eu1QYg2_b6DGcQpih-_u7N8j0-U4_NOITprMSfkGPGD2D6tS2fqQzHO96hbAciJsyF5LxThYPoFwwTKmJ_l-hW_hRPC_De-kN3KoMIvIFk-UVV693oZltN4V_lxAO_0SLBA.Fku-__prPSG6Lar1JvkNUC7OEd_D0Yhr-o1zmWILwBk)""");
	ConnectViaLoginFlowImpl(WorldContextObject, PlayerController, StrippedAuthToken);
	return;
#endif

	IOnlineIdentityPtr Identity = IOnlineSubsystem::Get()->GetIdentityInterface();
	int32 ControllerId = Player->GetControllerId();

	static FDelegateHandle OnLoginCompleteDelegateHandle;
	if (!OnLoginCompleteDelegateHandle.IsValid()) {
		auto Delegate = [WorldContextObject, PlayerController, Identity, ControllerId](int32 LocalUserNum, bool bWasSuccessful, const FUniqueNetId& UserId, const FString& Error) {
			if (bWasSuccessful)
			{
				FString AuthToken = Identity->GetAuthToken(ControllerId);
				UE_LOG(LogTemp, Warning, TEXT("Online subsystem login was successful. Sending deployment login request to our backend. UserId = %s. AuthToken = %s"), *UserId.ToDebugString(), *AuthToken);
				ConnectViaLoginFlowImpl(WorldContextObject, PlayerController, AuthToken.RightChop(30));
			}
			else
			{
				FString ErrorMessage = FString::Printf(TEXT("Login failed. Reason = %s"), *Error);
				GEngine->AddOnScreenDebugMessage(-1, 200.0f, FColor::Red, ErrorMessage);
				UE_LOG(LogTemp, Warning, TEXT("%s"), *ErrorMessage);
			}
		};
		OnLoginCompleteDelegateHandle = Identity->AddOnLoginCompleteDelegate_Handle(ControllerId, FOnLoginCompleteDelegate::CreateLambda(Delegate));
	}
	Identity->Login(ControllerId, FOnlineAccountCredentials());
}

void UMenuHelpers::ConnectViaReceptionist(UObject* WorldContextObject, ULocalPlayer* Player)
{
	APlayerController* PlayerController = Player->GetPlayerController(WorldContextObject->GetWorld());

	FURL URL;
	URL.Map = TEXT("ThirdPersonExampleMap");
	URL.AddOption(TEXT("receptionist"));
	URL.AddOption(TEXT("useExternalIpForBridge"));
	URL.Host = TEXT("172.16.116.141");
	URL.Port = 7777;

	UE_LOG(LogTemp, Log, TEXT("Attempting to travel to: %s"), *URL.ToString());
	PlayerController->ClientTravel(URL.ToString(), ETravelType::TRAVEL_Absolute);
}
