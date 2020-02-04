parallelism=256
declare -i MB=131072
declare -i IntArray=(1 10 100 200 300 400 500 600 700 800 900 1024) 
#declare -i IntArray=(1 10 100 1024)
# Iterate the string array using for loop
for val in ${IntArray[@]}; do
    z=$(( MB * val ))
    mb=$(( MB * 8 / 1024 / 1024))
    echo "Running Experiment for "${mb}" MB"
    mpirun -n ${parallelism} --hostfile nodes${parallelism} ./allreduce ${z} stats.csv    
done
