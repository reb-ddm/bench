# Generate asserts, as well as corresponding *.i, and *.yml files for sv-comp for the programs in bench/coreutils/.

# Execute with:
# python3 generate_yaml_for_coreutils.py
import os
from multiprocessing import Pool

def run_configuration(cwd,infile,outfile,uplevel,extraconf=""):
    os.chdir(cwd)
    goblint = uplevel + "/analyzer/goblint"

    if outfile == "":
        if infile.endswith(".c"):
            outfile = infile[:-2] + "_traces_rel.yml"
        else:
            raise ValueError("outfile must be specified for non-c files")

    enable_c2po="--set ana.activated[+] c2po --set ana.activated[+] startState --set ana.activated[+] taintPartialContexts"
    cmd = goblint + " --enable pre.keep " + extraconf +  " --set dbg.timeout 1200 " + enable_c2po + " -v  --enable witness.yaml.enabled "

    # --set witness.yaml.path ./aget_comb_traces_rel.yml
    command = cmd + " " + infile + " --set witness.yaml.path  " + outfile
    print("Executing command: " + command)
    os.system(command)

bench_dir = "/home/ddm2/master/bench/coreutils/"
posix_dir = bench_dir
tasks = [
    (posix_dir,"cksum_comb.c","","../.."),
    (posix_dir,"cp_comb.c","","../.."),
    (posix_dir,"cut_comb.c","","../.."),
    (posix_dir,"dd_comb.c","","../.."),
    (posix_dir,"df_comb.c","","../.."),
    (posix_dir,"du_comb.c","","../.."),
    (posix_dir,"ls_comb.c","","../.."),
    (posix_dir,"mv_comb.c","","../.."),
    (posix_dir,"nohup_comb.c","","../.."),
    (posix_dir,"ptx_comb.c","","../.."),
    (posix_dir,"sort_comb.c","","../.."),
    (posix_dir,"tail_comb.c","","../..")
]

def really_run_configuration(task):
    run_configuration(*task)

if __name__ == '__main__':
    with Pool(10) as p:
        p.map(really_run_configuration, tasks)
