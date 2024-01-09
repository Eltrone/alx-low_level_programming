#!/usr/bin/python3
"""Script pour analyser des logs et afficher des statistiques."""

import sys

status_codes = {str(code): 0 for code in [200, 301, 400, 401, 403, 404, 405, 500]}
total_size = 0
line_count = 0

try:
    for line in sys.stdin:
        parts = line.split()
        if len(parts) >= 2:
            status = parts[-2]
            size = parts[-1]

            if status in status_codes:
                status_codes[status] += 1

            try:
                total_size += int(size)
            except ValueError:
                pass

        line_count += 1
        if line_count % 10 == 0:
            print("File size: {}".format(total_size))
            for code, count in sorted(status_codes.items()):
                if count > 0:
                    print("{}: {}".format(code, count))

except KeyboardInterrupt:
    print("File size: {}".format(total_size))
    for code, count in sorted(status_codes.items()):
        if count > 0:
            print("{}: {}".format(code, count))
    raise
