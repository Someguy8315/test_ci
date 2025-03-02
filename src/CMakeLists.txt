project(func)

add_library(${PROJECT_NAME} SHARED func.cpp func.h)

target_include_directories(${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>)

target_link_libraries(${PROJECT_NAME} PUBLIC
    re2::re2
)

install(TARGETS ${PROJECT_NAME} # absl_absl_check
    absl_absl_log absl_base absl_core_headers absl_fixed_array absl_flags absl_flat_hash_map
    absl_flat_hash_set absl_hash absl_optional absl_span absl_str_format
    absl_strings absl_atomic_hook absl_base_internal absl_config
    absl_dynamic_annotations absl_log_severity absl_nullability absl_raw_logging_internal
    absl_type_traits absl_compressed_tuple absl_algorithm absl_spinlock_wait
    absl_throw_delegate absl_memory absl_flags_config absl_flags_internal
    absl_flags_reflection absl_container_memory absl_hash_container_defaults
    absl_meta absl_utility absl_no_destructor absl_flags_private_handle_accessor
    absl_flags_commandlineflag_internal absl_fast_type_id absl_flags_commandlineflag
    absl_flags_marshalling absl_flags_program_name absl_int128
    absl_errno_saver absl_bits absl_compare absl_flags_path_util absl_tracing_internal
    absl_time absl_civil_time absl_time_zone absl_symbolize absl_malloc_internal
    absl_demangle_internal absl_demangle_rust absl_decode_rust_punycode absl_debugging_internal
    absl_utf8_for_code_point absl_bounded_utf8_length_sequence absl_stacktrace
    absl_hash_function_defaults absl_graphcycles_internal absl_endian absl_cord
    absl_container_common absl_bad_optional_access absl_log_internal_check_impl
    absl_log_internal_log_impl absl_raw_hash_map absl_algorithm_container
    absl_raw_hash_set absl_city absl_function_ref absl_variant absl_low_level_hash
    absl_inlined_vector absl_absl_check absl_str_format_internal absl_string_view
    absl_strings_internal absl_charset absl_synchronization absl_cord_internal
    absl_cordz_functions absl_cordz_info absl_cordz_update_scope absl_cordz_update_tracker
    absl_crc32c absl_crc_cord_state absl_log_internal_check_op absl_log_internal_conditions
    absl_log_internal_message absl_log_internal_strip absl_absl_vlog_is_on absl_common_policy_traits
    absl_hash_policy_traits absl_hashtable_debug_hooks absl_hashtablez_sampler absl_prefetch
    absl_any_invocable absl_bad_variant_access absl_inlined_vector_internal absl_numeric_representation
    absl_kernel_timeout_internal absl_layout absl_exponential_biased absl_cordz_handle
    absl_cordz_statistics absl_crc_cpu_detect absl_crc_internal absl_non_temporal_memcpy
    absl_leak_check absl_log_internal_nullguard absl_log_internal_nullstream
    absl_log_internal_voidify absl_examine_stack absl_log_internal_append_truncated
    absl_log_internal_format absl_log_internal_globals absl_log_internal_proto absl_log_internal_log_sink_set
    absl_log_globals absl_log_internal_structured_proto absl_log_entry absl_log_sink absl_log_sink_registry
    absl_strerror absl_vlog_config_internal absl_sample_recorder absl_non_temporal_arm_intrinsics
    absl_log_internal_config absl_log_internal_fnmatch absl_cleanup absl_cleanup_internal
    EXPORT funcTargets
    DESTINATION lib
)

install(EXPORT funcTargets
    DESTINATION lib/cmake/${PROJECT_NAME}
    NAMESPACE ${PROJECT_NAME}::
)

install(FILES func.h
    DESTINATION include
)
