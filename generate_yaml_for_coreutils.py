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
    cmd = goblint + " --enable pre.keep " + extraconf +  " --set dbg.timeout 3600 " + enable_c2po + " -v  --enable witness.yaml.enabled "+ "--disable sem.unknown_function.spawn --disable sem.unknown_function.call --enable allglobs --enable dbg.timing.enabled "

    # --set witness.yaml.path ./aget_comb_traces_rel.yml
    command = cmd + " " + infile + " --set witness.yaml.path  " + outfile
    print("Executing command: " + command)
    os.system(command)

bench_dir = "/home/ddm2/master/bench/"
coreutils_dir = bench_dir + "coreutils_without_comments/"
reg_dir = bench_dir + "regression/83-c2po/"

tasks = [
    (coreutils_dir,"cksum_comb.c","","../.."),
    (coreutils_dir,"nohup_comb.c","","../.."),
    # (coreutils_dir,"cp_comb.c","","../.."),
    # (coreutils_dir,"cut_comb.c","","../.."),
    # (coreutils_dir,"dd_comb.c","","../.."),
    # (coreutils_dir,"df_comb.c","","../.."),
    # (coreutils_dir,"du_comb.c","","../.."),
    # (coreutils_dir,"ls_comb.c","","../.."),
    # (coreutils_dir,"mv_comb.c","","../.."),
    # (coreutils_dir,"ptx_comb.c","","../.."),
    # (coreutils_dir,"sort_comb.c","","../.."),
    # (coreutils_dir,"tail_comb.c","","../..")

    # (reg_dir,"01-simple.c","","../../.."),
    # (reg_dir,"02-rel-simple.c","","../../.."),
    # (reg_dir,"03-function-call.c","","../../.."),
    # (reg_dir,"04-remove-vars.c","","../../.."),
    # (reg_dir,"05-branch.c","","../../.."),
    # (reg_dir,"06-invertible-assignment.c","","../../.."),
    # (reg_dir,"07-invertible-assignment2.c","","../../.."),
    # (reg_dir,"08-simple-assignment.c","","../../.."),
    # (reg_dir,"09-different-offsets.c","","../../.."),
    # (reg_dir,"10-different-types.c","","../../.."),
    # (reg_dir,"11-array.c","","../../.."),
    # (reg_dir,"12-rel-function.c","","../../.."),
    # (reg_dir,"13-experiments.c","","../../.."),
    # (reg_dir,"14-join.c","","../../.."),
    # (reg_dir,"15-arrays-structs.c","","../../.."),
    # (reg_dir,"16-loops.c","","../../.."),
    # (reg_dir,"17-join2.c","","../../.."),
    # (reg_dir,"18-complicated-join.c","","../../.."),
    # (reg_dir,"19-disequalities.c","","../../.."),
    # (reg_dir,"20-self-pointing-struct.c","","../../.."),
    # (reg_dir,"21-global-var.c","","../../.."),
    # (reg_dir,"22-join-diseq.c","","../../.."),
    # (reg_dir,"23-function-deref.c","","../../.."),
    # (reg_dir,"26-join3.c","","../../.."),
    # (reg_dir,"25-struct-circular.c","","../../.."),
    # (reg_dir,"24-disequalities-small-example.c","","../../.."),
    # (reg_dir,"27-join-diseq2.c","","../../.."),
    # (reg_dir,"28-return-value.c","","../../.."),
    # (reg_dir,"29-widen.c","","../../.."),
]

def really_run_configuration(task):
    run_configuration(*task)

if __name__ == '__main__':
    with Pool(10) as p:
        p.map(really_run_configuration, tasks)
