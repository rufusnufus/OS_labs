i=1
while [ $i -le 100 ]
do
	tempfile=$(mktemp ./lock.XXXX)
	lockfile=./lockfile
	if ln $tempfile $lockfile
	then
		((i++))
		var=$(tail -n 1 file.txt)
        var=$((var+1))
        echo $var >> file.txt
        rm $lockfile
    fi
    rm $tempfile
done
echo "Finish."