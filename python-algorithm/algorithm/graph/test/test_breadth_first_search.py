import pytest, networkx


def create_city_graph() -> networkx.Graph:
    graph = networkx.Graph()
    graph.add_edge("Seattle", "Chicago")
    graph.add_edge("Seattle", "San Francisco")
    graph.add_edge("San Francisco", "Riverside")
    graph.add_edge("San Francisco", "Los Angeles")
    graph.add_edge("Los Angeles", "Riverside")
    graph.add_edge("Los Angeles", "Phoenix")
    graph.add_edge("Riverside", "Phoenix")
    graph.add_edge("Riverside", "Chicago")
    graph.add_edge("Phoenix", "Dallas")
    graph.add_edge("Phoenix", "Houston")
    graph.add_edge("Dallas", "Chicago")
    graph.add_edge("Dallas", "Atlanta")
    graph.add_edge("Dallas", "Houston")
    graph.add_edge("Houston", "Atlanta")
    graph.add_edge("Houston", "Miami")
    graph.add_edge("Atlanta", "Chicago")
    graph.add_edge("Atlanta", "Washington")
    graph.add_edge("Atlanta", "Miami")
    graph.add_edge("Miami", "Washington")
    graph.add_edge("Chicago", "Detroit")
    graph.add_edge("Detroit", "Boston")
    graph.add_edge("Detroit", "Washington")
    graph.add_edge("Detroit", "New York")
    graph.add_edge("Boston", "New York")
    graph.add_edge("New York", "Philadelphia")
    graph.add_edge("Philadelphia", "Washington")
    return graph


city_graph = create_city_graph()


@pytest.mark.benchmark(group='graph_neighbors')
@pytest.mark.parametrize(
    argnames='graph, source, expected_neighbors',
    argvalues=[
        (city_graph, "Seattle", ["Chicago", "San Francisco"]),
        (city_graph, "San Francisco", ["Seattle", "Riverside", "Los Angeles"]),
        (city_graph, "Los Angeles", ["San Francisco", "Riverside", "Phoenix"]),
        (city_graph, "Riverside", ["San Francisco", "Los Angeles", "Phoenix", "Chicago"]),
        (city_graph, "Phoenix", ["Los Angeles", "Riverside", "Dallas", "Houston"]),
        (city_graph, "Chicago", ["Seattle", "Riverside", "Dallas", "Atlanta", "Detroit"]),
        (city_graph, "Boston", ["Detroit", "New York"]),
        (city_graph, "New York", ["Detroit", "Boston", "Philadelphia"]),
        (city_graph, "Atlanta", ["Dallas", "Houston", "Chicago", "Washington", "Miami"]),
        (city_graph, "Miami", ["Houston", "Atlanta", "Washington"]),
        (city_graph, "Dallas", ["Phoenix", "Chicago", "Atlanta", "Houston"]),
        (city_graph, "Houston", ["Phoenix", "Dallas", "Atlanta", "Miami"]),
        (city_graph, "Detroit", ["Chicago", "Boston", "Washington", "New York"]),
        (city_graph, "Philadelphia", ["New York", "Washington"]),
        (city_graph, "Washington", ["Atlanta", "Miami", "Detroit", "Philadelphia"])
    ])
def test_graph_neighbors(benchmark, graph, source, expected_neighbors):
    """
    Find the neighboring city nodes of the source city node in the United States city graph.
    :param benchmark: benchmark fixture
    :param graph: city graph of the United States
    :param source: source city node
    :param expected_neighbors: list of neighboring city nodes
    """
    neighbor_iterator = benchmark(graph.neighbors, source)
    assert sorted(expected_neighbors) == sorted(neighbor_iterator)


@pytest.mark.benchmark(group='graph_breadth_first_search')
@pytest.mark.parametrize(
    argnames='graph, source, distance, expected_nodes',
    argvalues=[
        (city_graph, "Boston", 1, ["Detroit", "New York"]),
        (city_graph, "Boston", 2, ["Chicago", "Washington", "Philadelphia"]),
        (city_graph, "Boston", 3, ["Seattle", "Riverside", "Dallas", "Atlanta", "Miami"]),
    ],
    ids=['distance1', 'distance2', 'distance3'])
def test_graph_breadth_first_search(benchmark, graph, source, distance, expected_nodes):
    """
    Find the city nodes at a given distance from the source city node in the United States city graph.
    :param benchmark: benchmark fixture
    :param graph: city graph of the United States
    :param source: source city node
    :param distance: distance from the source city node
    :param expected_nodes: list of city nodes at the given distance from the source city node
    """
    bfs_generator = benchmark(networkx.bfs_layers, graph, source)
    nodes = []
    for i, layer in enumerate(bfs_generator):
        if i == distance:
            nodes = list(layer)
    assert nodes == expected_nodes
