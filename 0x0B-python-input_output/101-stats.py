#!/usr/bin/python3
import sys


def parse_line(line):
    """ Parse the line and return status code and file size. """
    parts = line.split(" ")
    status_code = parts[-2]
    file_size = int(parts[-1])
    return status_code, file_size


def print_stats(total_size, status_codes):
    """ Print the statistics. """
    print("File size: {}".format(total_size))
    for code in sorted(status_codes.keys()):
        print("{}: {}".format(code, status_codes[code]))


def main():
    """ Main function to parse logs and compute metrics. """
    total_size = 0
    status_codes = {}
    line_count = 0

    try:
        for line in sys.stdin:
            status_code, file_size = parse_line(line)
            total_size += file_size
            if status_code in status_codes:
                status_codes[status_code] += 1
            else:
                status_codes[status_code] = 1

            line_count += 1
            if line_count % 10 == 0:
                print_stats(total_size, status_codes)

    except KeyboardInterrupt:
        print_stats(total_size, status_codes)
        raise


if __name__ == "__main__":
    main()
