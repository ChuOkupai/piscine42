# -*- encoding: utf-8 -*-

Gem::Specification.new do |s|
  s.name = "amq-protocol"
  s.version = "2.0.0"

  s.required_rubygems_version = Gem::Requirement.new(">= 0") if s.respond_to? :required_rubygems_version=
  s.authors = ["Jakub Stastny", "Michael S. Klishin", "Theo Hultberg", "Mark Abramov"]
  s.date = "2015-08-15"
  s.description = "  amq-protocol is an AMQP 0.9.1 serialization library for Ruby. It is not a\n  client: the library only handles serialization and deserialization.\n"
  s.email = ["michael.s.klishin@gmail.com"]
  s.extra_rdoc_files = ["README.md"]
  s.files = ["README.md"]
  s.homepage = "http://github.com/ruby-amqp/amq-protocol"
  s.licenses = ["MIT"]
  s.require_paths = ["lib"]
  s.required_ruby_version = Gem::Requirement.new(">= 2.0")
  s.rubyforge_project = "amq-protocol"
  s.rubygems_version = "2.0.14"
  s.summary = "AMQP 0.9.1 encoding & decoding library."
end
