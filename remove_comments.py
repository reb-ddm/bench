import os

input_dir = "./coreutils/"
output_dir = "./coreutils_without_comments/"

def remove_comments(file):
    input = open(input_dir + file, "r")
    output = open(output_dir + file, "w")
    print("Starting to copy "+ file)
    for line in input.readlines():
        if(not line.startswith("#")):
            output.write(line)
    print("Finished copying "+ file)
    input.close()
    output.close()


for file in os.listdir(input_dir):
    if file.endswith(".c"):
        remove_comments(file)
