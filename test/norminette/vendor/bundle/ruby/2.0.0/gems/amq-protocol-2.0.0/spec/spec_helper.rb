# encoding: binary

require 'bundler/setup'
require 'rspec'
require 'rspec/its'

require "effin_utf8"

begin
  require 'simplecov'

  SimpleCov.start do
    add_filter '/spec/'
  end
rescue LoadError
end

$: << File.expand_path('../../lib', __FILE__)

require "amq/protocol"

puts "Running on #{RUBY_VERSION}"

RSpec.configure do |config|
  config.include AMQ::Protocol

  config.warnings = true
end
