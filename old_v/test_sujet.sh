echo "pickle rick" | openssl md5
echo "pickle rick" | md5
echo "pickle rick" | ./ft_ssl md5
echo "Do not pity the dead, Harry." | ./ft_ssl md5 -p
echo "Pity the living." | ./ft_ssl md5 -q -r
echo "And above all," > file
./ft_ssl md5 file
./ft_ssl md5 -r file
./ft_ssl md5 -s "pity those that aren't following baerista on spotify."
echo "be sure to handle edge cases carefully" | ./ft_ssl md5 -p file
echo "some of this will not make sense at first" | ./ft_ssl md5 file
echo "but eventually you will understand" | ./ft_ssl md5 -p -r file
echo "GL HF let's go" | ./ft_ssl md5 -p -s "foo" file
echo "one more thing" | ./ft_ssl md5 -r -p -s "foo" file -s "bar"
echo "just to be extra clear" | ./ft_ssl md5 -r -q -p -s "foo" file
