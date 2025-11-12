
function(add_day day_number)
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
        io.c
    )     # the actual source file

    # -----------------------------------------------------------------
    # 4️⃣ Create the executable using the padded name
    # -----------------------------------------------------------------
    add_executable(${binary_name} ${${src_var}})
    target_compile_definitions(${binary_name} PRIVATE RUN_STANDALONE)
    target_link_libraries(${binary_name} PRIVATE clogger)

    # -----------------------------------------------------------------
    # 5️⃣ Expose the source list to the caller (if you need it)
    # -----------------------------------------------------------------
    set(DAY${day_padded}_SOURCES ${${src_var}} PARENT_SCOPE)
endfunction()