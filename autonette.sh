cd 42
while :; do
	output=$(norminette)
	clear
	echo "$output"
	sleep 0.2
done
