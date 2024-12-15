FROM alpine:latest

RUN apk update && apk add --no-cache git build-base

WORKDIR /app
RUN git clone https://github.com/Spectr21/PARVPO_LAB1.git .

RUN g++ -fopenmp load_cpu.cpp -o load_cpu

CMD ["sh", "-c", "./load_cpu > /output/result.txt"]
