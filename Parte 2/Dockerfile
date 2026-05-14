FROM gcc:latest

WORKDIR /app

COPY ["Disk scheduling.h", "./"]
COPY ["Disk scheduling.cpp", "./"]
COPY ["report.h", "./"]
COPY ["report.cpp", "./"]
COPY ["main.cpp", "./"]
COPY ["entrypoint.sh", "./"]
COPY ["index.html", "./"]  

RUN g++ -std=c++17 -O2 -o scheduler \
        main.cpp "Disk scheduling.cpp" report.cpp

RUN chmod +x entrypoint.sh

EXPOSE 8080

ENTRYPOINT ["./entrypoint.sh"]