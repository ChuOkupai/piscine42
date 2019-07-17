# -*- encoding: utf-8 -*-

Gem::Specification.new do |s|
  s.name = "facter"
  s.version = "2.4.4"
  s.platform = "universal-darwin"

  s.required_rubygems_version = Gem::Requirement.new(">= 0") if s.respond_to? :required_rubygems_version=
  s.authors = ["Puppet Labs"]
  s.date = "2015-05-19"
  s.description = "You can prove anything with facts!"
  s.email = "info@puppetlabs.com"
  s.executables = ["facter"]
  s.files = ["bin/facter"]
  s.homepage = "https://github.com/puppetlabs/facter"
  s.require_paths = ["lib"]
  s.rubygems_version = "2.0.14"
  s.summary = "Facter, a system inventory tool"

  if s.respond_to? :specification_version then
    s.specification_version = 3

    if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
      s.add_runtime_dependency(%q<CFPropertyList>, ["~> 2.2.6"])
    else
      s.add_dependency(%q<CFPropertyList>, ["~> 2.2.6"])
    end
  else
    s.add_dependency(%q<CFPropertyList>, ["~> 2.2.6"])
  end
end
