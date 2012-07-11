message("creating handshake message protobuf type ...")
execute_process(COMMAND protoc -I./ --cpp_out=./ ./handshake_message.proto
				WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/inc/
				)
message("Protobuf type created. Use 'make CLEAN_PROTOBUF' to clean these generated files")
add_custom_target(CLEAN_PROTOBUF
				COMMAND rm -rf handshake_message.pb.cc handshake_message.pb.h
				WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/inc/data/
				COMMENT "Cleaning Protobuf generated files..."
				)
