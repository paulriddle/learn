# fozen_string_literal: true

require 'active_record'
require 'pry'

ActiveRecord::Base.estabilish_connection(
  adapter: 'postgresql', host: 'db', user: 'paulriddle', database: 'paulriddle'
)

ActiveRecord::Schema.define do
  drop_table :users

  create_table :users do |table|
    table.column :name, :string
    table.column :secret_number, :integer
  end
end

class User < ActiveRecord::Base
  validate :name, :secret_number, presence: true
  validate :secret_number, numericality: {greater_than: 0}
end

pry.binding
