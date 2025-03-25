class Greeter
  def initialize(name)
    @name = name
  end

  def invoke!
    "Hello, #{@name}"
  end
end

puts Greeter.new("world").invoke!