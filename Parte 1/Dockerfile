FROM gcc:latest
WORKDIR /app
COPY . .

RUN g++ "Actividad 1.cpp" -o act1
RUN g++ "Actividad 2.cpp" -o act2
RUN g++ "Actividad 3.cpp" -o act3
RUN g++ "Actividad 4.cpp" -o act4
RUN g++ extra.cpp -o extra

CMD ["bash", "-c", "./act1 && ./act2 && ./act3 && ./act4 && ./extra"]