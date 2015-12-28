PROJECT_CEEDLING_ROOT = "vendor/ceedling"
load "#{PROJECT_CEEDLING_ROOT}/lib/ceedling.rb"


load "scripts/helper.rb"
# with this now we can choose which '.yml' configuration file to be loaded by
# issuing e.g. : 
project_file = get_value_from_env('project', './project.yml')

Ceedling.load_project(config: project_file)

load_extra_scripts(project_file)

desc 'Build and deplay'
task :build_and_deplay do

system "rake hw:flash"
end

task :default => %w[ build_and_deplay test:all ]
