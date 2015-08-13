prob=colisoes

for i in `seq 1 1 20`
do
	for j in 1 2 3 7
	do
		echo $i $j
		./a.out <$prob/test$i/in$j >out.txt
		diff $prob/test$i/out$j out.txt
	done

done
