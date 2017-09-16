var loggedin = 0;
var Steam = require('steam'),
        util = require("util"),
        fs = require("fs"),
        steamClient = new Steam.SteamClient(),
        steamUser = new Steam.SteamUser(steamClient),
        steamFriends = new Steam.SteamFriends(steamClient),
        steamGC = new Steam.SteamGameCoordinator(steamClient, 730),
        csgo = require('csgo')
        CSGO = new csgo.CSGOClient(steamUser, steamGC, false);
        readlineSync = require("readline-sync"),
        crypto = require("crypto");

function MakeSha(bytes){
        var hash = crypto.createHash('sha1')
        hash.update(bytes);
        return hash.digest();}
var request = require('request');
var url = "http://steamcommunity.com/market/listings/730/AK-47%20%7C%20Redline%20%28Field-Tested%29";
var username = "obama_stole_my_dog";
var password = "Niggers1286";

steamClient.connect();

steamClient.on('connected', function(){
        steamUser.logOn({
                "account_name": username,
                "password": password});});

steamClient.on('logOnResponse', function(response){
        if (response.eresult == Steam.EResult.OK){
                loggedin = 1;
                console.log('Logged In!');
                steamFriends.setPersonaState(Steam.EPersonaState.Busy);
                console.log("Current SteamID64: " + steamClient.steamID);
                console.log("Account ID: " + CSGO.ToAccountID(steamClient.steamID));
                CSGO.launch();}});

CSGO.on("ready", function(){CSGO.itemDataRequest("76561198218077912", "3162370634", "14909734931962909189", "0");});
CSGO.on("itemData", function(itemdata){
        console.log(itemdata);
        request
                .get(url)
                .on('response', function(response){console.log(response);});
        console.log("Request Sent!");
        console.log("Exiting CSGO...");
        CSGO.exit();
        console.log("Disconnecting From Steam...");
        steamClient.disconnect();});

steamUser.on('updateMachineAuth', function(response, callback){
        fs.writeFileSync('sentry', response.bytes);
        callback({sha_file: MakeSha(response.bytes)});});
