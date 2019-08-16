#!/bin/bash

set -u -o pipefail -x -e

MINPARAMS=3

if [ $# -lt "$MINPARAMS" ]; then
	echo "usage: run.sh {scenario} {snapshot} {id tag}"
	exit 1
fi

if [ ! -f $1 ]; then
	echo "Scenario $1 does not exist!"
	exit 1
fi

DATE=`date +%b%d_%H_%M  | tr '[:upper:]' '[:lower:]'` 
DEPLOYMENTNAME=$3
ASSEMBLYNAME=$DEPLOYMENTNAME

if [ ! -f $2 ]; then
	echo "Snapshot $2 does not exist!"
	exit 1
fi

spatial upload $ASSEMBLYNAME --force --environment=staging
spatial project history snapshot upload $DEPLOYMENTNAME "$2" --tags regisseur --environment=staging
regisseur version
regisseur run --scenarios=$1 --override_deployment_name=$DEPLOYMENTNAME --override_assembly_name=$ASSEMBLYNAME --raw_logs_download_at_end_of_deployment=true --environment=staging
