#!/bin/sh
HEAD_POS=${HEAD:-2500}

echo "=== Disk Scheduling ==="
echo "Cabeza inicial: $HEAD_POS"
echo ""

./scheduler "$HEAD_POS"

echo "Visualizacion disponible en http://localhost:8080"
echo ""

python3 -m http.server 8080