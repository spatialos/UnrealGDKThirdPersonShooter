#!/bin/sh

set -e

cd "$(dirname "$0")"

main() {
    if [ $# -eq 0 ]; then
        showHelp
        exit 1
    fi

    OPTION=$1
    shift

    case "$OPTION" in
        "launch" )
            launchScenario "$@" ;;
        "list" )
            listScenarios ;;
        "help" )
            showHelp ;;
         *)
            echo "Unknown command.\n"
            showHelp
    esac
}

showHelp() {
    echo "Available options:"
    echo "  launch [scenario_path]  Runs a regisseur scenario from the given configuration"
    echo "  list                    Shows all scenarios with descriptions"
}

launchScenario() {
    local scenario_path=$1
    regisseur run \
        --scenarios ${scenario_path} \
        --visualizers dump-errors,file-csv-matrix \
        --raw_logs_download_at_end_of_deployment \
        --raw_logs_download_if_scenario_passes \
        --raw_logs_max_size_megabytes 1024
}

listScenarios() {
    for f in "./**/*.pb.json"; do echo -n $f; echo -ne '\t'; jq -r .comment $f; done
}

main "$@"