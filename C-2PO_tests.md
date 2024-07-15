## C-2PO Benchmarks

### Generate Invariants

Execute the python script `python3 generate_yaml_for_coreutils.py`.
The result .yaml files containing the invariants will be in the folder `coreutils_without_comments`
and they have the same name as the corresponding C file, with the ending `_traces_rel.yml`.

### Validate Invariants

Execute the ruby script `ruby generate_witness-result.rb`.
It will try to validate the invariants first with base, then with C-2PO.
The result will be in the folder `witness_results_c2po`.
For a graphical representation, see the file `witness_results_c2po/index.html`.
