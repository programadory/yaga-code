# yaga-code-git

# Optimized code, using better function to saver space and memory.

# Implemment pointers in the future, cast with enum type. For now is finished.

# Problem when passing 0 arguments (segment fault erorr) solved.
# Cmatrix option implemented yaga [matrix]


# ---Tips and learning I did get.

# strcmp() return trash from memory if you doesn use the variables correctly. If a variable get trash in it, strcmp() cannot process this inexistent data, cuz *argv[] wasn't declared yet, it's dynamic allocated.

# --- Things to do  ------ #
 
# 1 - Correct call function every time, just execute once if tag_cmp() is true. - Use BUFFER-ON/BUFFER-OFF to do it.
# 2 - ln 93 executing every time due the "recursive" effect of yaga_main(). Correct firsth and that will be solved automatically.