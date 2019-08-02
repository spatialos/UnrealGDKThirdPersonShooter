// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Threading;

namespace WorkerCoordinator
{
    /// <summary>
    /// Executable that runs simulated players in batches, with a user-specified delay.
    /// The class defines the executable that should be given to regisseur to run simulated players. 
    /// It accepts 3 integer arguments from the command line:
    /// simulated_player_spawn_count={value}
    /// coordinator_spawn_interval_millis={value}
    /// coordinator_start_delay_millis={value}
    /// 
    /// Increase the batch_size to spawn more clients between pausing.
    /// These arguments must be given in this form or omitted.
    /// </summary>
    internal static class WorkerCoordinator
	{
		private const string SPAWN_COUNT_ARG = "simulated_player_spawn_count";
		private const string SPAWN_INTERVAL_ARG = "coordinator_spawn_interval_millis";
		private const string START_DELAY_ARG = "coordinator_start_delay_millis";
		private const string WORKER_NAME_ARG = "<IMPROBABLE_WORKER_ID>";

		private const string SIMULATED_PLAYER_FILENAME = "StartSimulatedClient.sh";

		private static Stack<Process> SimulatedPlayerList = new Stack<Process>();
		private static Logger Logger = new Logger("/improbable/logs/WorkerCoordinator.log");
		private static Random random = new Random();

		private static int Main(string[] args)
		{
			Logger.WriteLog("Starting coordinator with args: " + ArgsToString(args));

			var batchSize = GetIntegerArgument(args, SPAWN_COUNT_ARG, 1);
			var spawnIntervalMillis = GetIntegerArgument(args, SPAWN_INTERVAL_ARG, 0);
			var startDelayMillis = GetIntegerArgument(args, START_DELAY_ARG, 0);

			args = args.Skip(3).ToArray();

			Thread.Sleep(startDelayMillis);
			for (int i = 0; i < batchSize; ++i)
			{
				string[] clientArgs = args.ToArray();
				string clientName = "simulatedplayer" + Guid.NewGuid();
				for (int j = 0; j < clientArgs.Length; j++)
				{
					if (clientArgs[j] == WORKER_NAME_ARG)
					{
						clientArgs[j] = clientName;
					}
				}

				Logger.WriteLog("Starting worker " + clientName + " with args: " + ArgsToString(clientArgs));
				StartClient(string.Join(" ", clientArgs));
				Thread.Sleep(spawnIntervalMillis);
			}

			// Wait for all clients to have exited
			while (SimulatedPlayerList.Count > 0)
			{
				try
				{
                    SimulatedPlayerList.Pop().WaitForExit();
				} catch (Exception e)
				{
					Logger.WriteError("Error while waiting for simulated player to exit: " + e.Message);
				}
			}
			
			return 0;
		}

		private static int GetIntegerArgument(IEnumerable<string> args, string argumentName, int defaultValue)
		{
			var argumentsWithName = args.Where(arg => arg.StartsWith(argumentName)).ToArray();
			if (!argumentsWithName.Any())
			{
				return defaultValue;
			}

			if (argumentsWithName.Length == 1)
			{
				var valueString = argumentsWithName.Single().Split(new[] {'='}, 2, StringSplitOptions.None)[1];
				int value;
				if (int.TryParse(valueString, out value))
				{
					return value;
				}
				throw new ArgumentException($"Cannot parse value,\"{valueString}\", for argument \"{argumentName}\".");
			}
			throw new ArgumentException($"Multiple values for argument, \"{argumentName}\".");
		}

		private static string GetStringArgument(IEnumerable<string> args, string argumentName, string defaultValue)
		{
			var argumentsWithName = args.Where(arg => arg.StartsWith(argumentName)).ToArray();
			if (!argumentsWithName.Any())
			{
				return defaultValue;
			}

			if (argumentsWithName.Length == 1)
			{
				return argumentsWithName.Single().Split(new[] {'='}, 2, StringSplitOptions.None)[1];
			}
			throw new ArgumentException($"Multiple values for argument, \"{argumentName}\".");
		}

		private static void StartClient(string args)
		{
			if (SimulatedPlayerList != null)
			{
				try
				{
                    SimulatedPlayerList.Push(Process.Start(SIMULATED_PLAYER_FILENAME, args));
				} catch (Exception e)
				{
					Logger.WriteError("Exception from starting simulated player: " + e.Message);
				}
			} else
			{
				Logger.WriteError("SimulatedPlayerList was null");
			}
		}
		
		private static string ArgsToString(string[] args)
		{
			string result = "";
			foreach (string arg in args)
			{
				result += arg + ", ";
			}

			if (result.Length >= 2)
			{
				result.Remove(result.Length - 2);
			}

			return result;
		}
	}
}
