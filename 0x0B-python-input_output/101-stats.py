#!/usr/bin/python3
import sys
import signal

def print_stats(total_size, status_codes):
    print("File size: {}".format(total_size))
    for code in sorted(status_codes.keys()):
        print("{}: {}".format(code, status_codes[code]))

def signal_handler(sig, frame):
    print_stats(total_size, status_codes)
    sys.exit(0)

# Initialisation des variables
total_size = 0
status_codes = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}
line_count = 0

# Configuration du gestionnaire de signal pour CTRL+C
signal.signal(signal.SIGINT, signal_handler)

try:
    for line in sys.stdin:
        parts = line.split()
        status_code = int(parts[-2])
        file_size = int(parts[-1])

        # Mise à jour des statistiques
        total_size += file_size
        if status_code in status_codes:
            status_codes[status_code] += 1

        line_count += 1
        if line_count % 10 == 0:
            print_stats(total_size, status_codes)

except KeyboardInterrupt:
    pass
finally:
    print_stats(total_size, status_codes)
