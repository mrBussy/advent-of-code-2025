# ------------------------------------------------------------
# Function: make_day_script(<day_padded>)
#
# Example:
#   make_day_script(1)   # → creates day1.sh
#   make_day_script(6)   # → creates day6.sh
#
# ------------------------------------------------------------
function(make_day_script day_padded)
    # Guard against non‑numeric input
    if(NOT day_padded MATCHES "^[0-9]+$")
        message(FATAL_ERROR "make_day_script: argument must be a non‑negative integer")
    endif()

    # Build the filename (relative to the binary dir)
    set(script_name "day${day_padded}.sh")
    set(script_path "${CMAKE_BINARY_DIR}/${script_name}")

    # ------------------------------------------------------------------
    # Write the script contents.
    # Feel free to replace the echo line with whatever you need.
    # ------------------------------------------------------------------
    configure_file(${CMAKE_SOURCE_DIR}/include/script.sh.in ${script_path} @ONLY)

    # Make the file executable (POSIX only – on Windows it’s a no‑op)
    if(UNIX)
        file(CHMOD "${script_path}" PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE)
    endif()

    message(STATUS "Created script: ${script_path}")
endfunction()

function(aoc_add_puzzle TARGET_BINARY day_number)
    # -----------------------------------------------------------------
    # 1️⃣ Pad the day number to two digits (01, 02 … 09, 10, 11 …)
    # -----------------------------------------------------------------

    # Fallback for older CMake: prepend a zero and strip if >9
    if(day_number LESS 10)
        set(day_padded "0${day_number}")
    else()
        set(day_padded "${day_number}")
    endif()

    # -----------------------------------------------------------------
    # 2️⃣ Build the names of the variables we will create
    # -----------------------------------------------------------------
    #   DAY${day_padded}_BINARY   →  e.g. MyRun_DAY01
    #   DAY${day_padded}_SOURCES  →  e.g. DAY1_SOURCES (the list itself)
    # -----------------------------------------------------------------
    set(binary_name "${FULL_RUN_BINARY}_DAY${day_padded}")

    # Store the binary name in the parent scope (optional, keep your API)
    set(DAY${day_padded}_BINARY "${binary_name}" PARENT_SCOPE)

    # -----------------------------------------------------------------
    # 3️⃣ Create the source‑list variable (indirect expansion)
    # -----------------------------------------------------------------
    set(src_var "DAY${day_padded}_SOURCES")   # e.g. DAY1_SOURCES
    set(${src_var} "day${day_padded}.c"
    )

    # -----------------------------------------------------------------
    # 4️⃣ Create a script to start running the correct day
    # -----------------------------------------------------------------

    make_day_script(${day_padded})
    target_sources(${TARGET_BINARY} PRIVATE ${${src_var}})

    # -----------------------------------------------------------------
    # 5️⃣ Expose the source list to the caller (if you need it)
    # -----------------------------------------------------------------
    set(DAY${day_padded}_SOURCES ${${src_var}} PARENT_SCOPE)
endfunction()