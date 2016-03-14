#! /usr/bin/env coffee
module.exports = () ->
	rainfall = require "./data/rain.json"
	rainfall.total = () ->
		sum = 0
		for datum in @
			sum += datum
		sum

	days = rainfall.length
	avg = rainfall.total() / days

	if days is 0
		console.log "There was no period during this rain."
	else if avg is 0
		console.log "There was no rain during this period."
	else
		console.log "The average rainfall over #{days} days " +
			"was #{avg} inches"

if module is require.main
	module.exports()