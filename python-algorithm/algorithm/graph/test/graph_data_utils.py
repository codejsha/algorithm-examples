import networkx

seattle = 'Seattle'
san_francisco = 'San Francisco'
los_angeles = 'Los Angeles'
riverside = 'Riverside'
phoenix = 'Phoenix'
dallas = 'Dallas'
houston = 'Houston'
atlanta = 'Atlanta'
miami = 'Miami'
chicago = 'Chicago'
detroit = 'Detroit'
boston = 'Boston'
new_york = 'New York'
philadelphia = 'Philadelphia'
washington = 'Washington'


def create_city_graph() -> networkx.Graph:
    edges = [
        (seattle, chicago),
        (seattle, san_francisco),
        (san_francisco, riverside),
        (san_francisco, los_angeles),
        (los_angeles, riverside),
        (los_angeles, phoenix),
        (riverside, phoenix),
        (riverside, chicago),
        (phoenix, dallas),
        (phoenix, houston),
        (dallas, chicago),
        (dallas, atlanta),
        (dallas, houston),
        (houston, atlanta),
        (houston, miami),
        (atlanta, chicago),
        (atlanta, washington),
        (atlanta, miami),
        (miami, washington),
        (chicago, detroit),
        (detroit, boston),
        (detroit, washington),
        (detroit, new_york),
        (boston, new_york),
        (new_york, philadelphia),
        (philadelphia, washington)
    ]
    graph = networkx.Graph()
    graph.add_edges_from(edges)
    return graph


def create_weighted_city_graph() -> networkx.Graph:
    weighted_edges = [
        (seattle, chicago, 1737),
        (seattle, san_francisco, 678),
        (san_francisco, riverside, 386),
        (san_francisco, los_angeles, 348),
        (los_angeles, riverside, 50),
        (los_angeles, phoenix, 357),
        (riverside, phoenix, 307),
        (riverside, chicago, 1704),
        (phoenix, dallas, 887),
        (phoenix, houston, 1015),
        (dallas, chicago, 805),
        (dallas, atlanta, 721),
        (dallas, houston, 225),
        (houston, atlanta, 702),
        (houston, miami, 968),
        (atlanta, chicago, 588),
        (atlanta, washington, 543),
        (atlanta, miami, 604),
        (miami, washington, 923),
        (chicago, detroit, 238),
        (detroit, boston, 613),
        (detroit, washington, 396),
        (detroit, new_york, 482),
        (boston, new_york, 190),
        (new_york, philadelphia, 81),
        (philadelphia, washington, 123)
    ]
    graph = networkx.Graph()
    graph.add_weighted_edges_from(weighted_edges)
    return graph
