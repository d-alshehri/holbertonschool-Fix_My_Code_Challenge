# Sort integer arguments (ascending)
result = ARGV.select { |arg| arg =~ /^-?\d+$/ }  # keep only integers
               .map(&:to_i)                        # convert to integer
               .sort                                # sort ascending

puts result
