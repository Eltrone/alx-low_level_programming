import sys
import signal

# Initialisation des variables
total_size = 0
status_codes = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}
line_count = 0

def print_stats():
    """ Fonction pour imprimer les statistiques """
    print("File size: {}".format(total_size))
    for code in sorted(status_codes.keys()):
        if status_codes[code] > 0:
            print("{}: {}".format(code, status_codes[code]))

def signal_handler(sig, frame):
    """ Gère l'interruption du clavier (CTRL + C) """
    print_stats()
    sys.exit(0)

# Configuration du gestionnaire de signal pour CTRL + C
signal.signal(signal.SIGINT, signal_handler)

# Lecture de stdin ligne par ligne
try:
    for line in sys.stdin:
        parts = line.split()
        try:
            size = int(parts[-1])
            status_code = int(parts[-2])
            total_size += size
            if status_code in status_codes:
                status_codes[status_code] += 1
        except (ValueError, IndexError):
            pass  # Gère les erreurs de format de ligne

        line_count += 1
        if line_count % 10 == 0:
            print_stats()

except KeyboardInterrupt:
    pass

# Affiche les statistiques finales
print_stats()
