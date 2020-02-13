parallelism=256
declare -i MB=131072
declare -i IntArray=(1 10 100 200 300 400 500 600 700 800 900 1024) 
#declare -i IntArray=(1 10 100 1024)
# Iterate the string array using for loop
for val in ${IntArray[@]}; do
    z=$(( MB * val ))
    mb=$(( MB * 8 / 1024 / 1024))
    echo "Running Experiment for "${mb}" MB"
    mpirun --mca coll_base_verbose 1 --mca btl_openib_allow_ib 1 -n ${parallelism} --hostfile nodes${parallelism} ./allreduce ${z} stats_ib.csv 
done
