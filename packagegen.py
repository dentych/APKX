import random


NUM_PACKAGES = 10**3
PACKAGE_TYPES = [
    'LegalPackage',
    'Hash',
    'Heroin',
    'DonaldTrumpMerchandise',
    'Ugyldig',
]
PACKAGE_DESTINATIONS = [
    'DEN',
    'GER',
    'GBR',
    'FRA',
    'USA',
    'RHO',
    'SPA',
    'RUS',
    'SWE',
]


def create_package():
    package_type = random.choice(PACKAGE_TYPES)
    destination = random.choice(PACKAGE_DESTINATIONS)
    weight = random.randint(10, 100)

    return package_type, destination, str(weight)


def generate_package_list(tofile):
    for i in range(NUM_PACKAGES):
        package = create_package()
        tofile.write('%s\n' % ' '.join(package))


if __name__ == '__main__':
    with open('packages.txt', 'w') as tofile:
        generate_package_list(tofile)
