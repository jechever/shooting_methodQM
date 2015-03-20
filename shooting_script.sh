#!/bin/bash
#Run code for various values of E and plot in real time

COUNTER=0
NUM_EVALS=10
#Make an array of E/V0 values (spaced from -1 to 0)
while [ $COUNTER -lt $NUM_EVALS ]; do
  let EVALS[$COUNTER]=-1+$COUNTER*1/$NUM_EVALS
  let COUNTER=$COUNTER+1
done

make clean
make

#Run the code with each value of E and plot using gnuplot
for value in $EVALS; do
    echo Starting run with E=$value
    echo `./shooting $value`
    gnuplot -persist -e "plot 'output.dat'" loop.plt
  #loop.plt refreshes the plot
#if ($status) echo WARNING: Problem during execution
done