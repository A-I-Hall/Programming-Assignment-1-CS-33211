# Use an official Ubuntu image as the base image
FROM ubuntu:20.04

# Set the working directory
WORKDIR /app

# Install required packages
RUN apt-get update && \
    apt-get install -y build-essential g++ && \
    apt-get clean

# Copy the current directory contents into the container at /app
COPY . .

# Compile the producer and consumer programs
RUN g++ producer.cpp -pthread -lrt -o producer
RUN g++ consumer.cpp -pthread -lrt -o consumer

# Command to run the programs
CMD ["bash"]
