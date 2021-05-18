# Converter decimal para binário

dec = 0

while dec < 1 || dec > 100
  puts 'Entre um número de 1 a 100:' 
  dec = gets.to_i 
end

@binario = ''

while dec != 0
  result = (dec / 2).floor
  @binario = (dec % 2).to_s + @binario
  dec = result
end

p @binario.to_i