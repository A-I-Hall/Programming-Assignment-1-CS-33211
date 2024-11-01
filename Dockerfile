# Use an official Ubuntu image as the base image
FROM ubuntu:20.04

# Set the working directory
WORKDIR /app

# Install required packages
RUN apt-get update && \
    apt-get install -y build-essential g++ && \
    apt-get clean

# Copy all contents of the current directory into the container
COPY . .

# Compile the producer and consumer programs
RUN g++ producer.cpp -pthread -lrt -o producer
RUN g++ consumer.cpp -pthread -lrt -o consumer

# Command to keep the container running
CMD ["bash"]
