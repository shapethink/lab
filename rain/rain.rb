#! /usr/bin/env ruby
require "yaml"
data = YAML.load File.read "data/rain.yaml"

total = data.inject(0, &:+)
days = data.size
avg = total / days

if data.empty?
	puts "There was no period for this rainfall"
elsif avg == 0.0
	puts "There was no rainfall for this period"
else
	puts "The average rainfall over #{days} days was #{avg} inches."
end