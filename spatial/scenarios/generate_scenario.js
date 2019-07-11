let fs = require("fs");
let path = require("path");

let PLAYERS_PER_NODE = 10;
let INITITAL_DELAY = 10000;
let INTERVAL_BETWEEN_PLAYERS = 3000;

function addFakeClients(scenarioFile, numPlayers) {
	let scenario = JSON.parse(fs.readFileSync(scenarioFile, "UTF-8"));

	let templateNode = scenario.genericClientNodes[0];

	scenario.genericClientNodes = [];

	let currentDelay = INITITAL_DELAY;

	let nodeIndex = 0;
	while(numPlayers > 0) {
		let thisNode = JSON.parse(JSON.stringify(templateNode));
		thisNode.name = "sim_player_node" + numPlayers;

		let startDelay = currentDelay;
		let playersOnNode = Math.min(numPlayers, PLAYERS_PER_NODE);
		numPlayers -= playersOnNode;
		currentDelay += playersOnNode * INTERVAL_BETWEEN_PLAYERS;

		for(let i=0; i<thisNode.config.command.args.length; i++) {
			if(thisNode.config.command.args[i].indexOf("coordinator_start_delay_millis") === 0) {
				thisNode.config.command.args[i] = "coordinator_start_delay_millis=" + startDelay;
			}
			if(thisNode.config.command.args[i].indexOf("coordinator_spawn_interval_millis") === 0) {
				thisNode.config.command.args[i] = "coordinator_spawn_interval_millis=" + INTERVAL_BETWEEN_PLAYERS;
			}
			if(thisNode.config.command.args[i].indexOf("simulated_player_spawn_count") === 0) {
				thisNode.config.command.args[i] = "simulated_player_spawn_count=" + playersOnNode;
			}
			if(thisNode.config.command.args[i].indexOf("node_index") === 0) {
				thisNode.config.command.args[i] = "node_index=" + nodeIndex;
			}
		}
		
		nodeIndex++;

		scenario.genericClientNodes.push(thisNode);
	}

	fs.writeFileSync(scenarioFile + ".gen.json", JSON.stringify(scenario, null, 4));
}

addFakeClients(path.resolve(__dirname, "./16_25_zones.pb.json"), 600);