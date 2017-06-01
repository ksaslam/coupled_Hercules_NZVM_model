# System definition
# -----------------

SYSTEM = MAVERICKS

# Main compilation setup
# ----------------------

#CFLAGS += -O3
CFLAGS += -g -O0 -DDEBUG

# Compilation flags
# -----------------

# CVM and IO related:

# to use it for topography
GSL_INCLUDE_PATH=/usr/local/Cellar/gsl/1.16/include/gsl
GSL_LIBRARY_PATH=/usr/local/Cellar/gsl/1.16/lib/libgsl.a

LDFLAGS += /usr/local/Cellar/gsl/1.16/lib/libgsl.a

IO_CFLAGS = -DUSECVMDB -DSCEC -DPROCPERNODE=1 -DNO_OUTPUT
#IO_CPPFLAGS = -DUSECVMDB -DSCEC -DPROCPERNODE=1 -DNO_OUTPUT

#IO_CPPFLAGS = -DUSECVMDB -DSCEC -DPROCPERNODE=1 -DNO_OUTPUT
IO_CPPFLAGS = -DUSECVMDB -DSCEC -DPROCPERNODE=1 -DNO_OUTPUT -I$(GSL_INCLUDE_PATH) -L$(GSL_LIBRARY_PATH)

# Earthquake related

SOLVE_CFLAGS = -DHALFSPACE -DBOUNDARY
SOLVE_CPPFLAGS = -DHALFSPACE -DBOUNDARY
