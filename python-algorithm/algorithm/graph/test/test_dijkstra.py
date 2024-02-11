import networkx
import pytest

from algorithm.graph.test.graph_data_utils import create_weighted_city_graph

city_graph = create_weighted_city_graph()


@pytest.mark.benchmark(group='graph_dijkstra')
@pytest.mark.parametrize(
    argnames='graph, source, target, expected_path',
    argvalues=[
        (city_graph, 'Los Angeles', 'Boston', ['Los Angeles', 'Riverside', 'Chicago', 'Detroit', 'Boston']),
    ],
    ids=['los_angeles_to_boston'])
def test_graph_dijkstra_path(benchmark, graph, source, target, expected_path):
    """
    Find the shortest path between two nodes in a graph using Dijkstra's algorithm.
    :param benchmark: benchmark fixture
    :param graph: city graph of the United States
    :param source: source city node
    :param target: target city node
    :param expected_path: expected shortest path
    """
    shortest_path = benchmark(networkx.dijkstra_path, graph, source, target)
    assert shortest_path == expected_path


@pytest.mark.benchmark(group='graph_dijkstra')
@pytest.mark.parametrize(
    argnames='graph, source, target, expected_distance',
    argvalues=[
        (city_graph, 'Los Angeles', 'Boston', 2605),
    ],
    ids=['los_angeles_to_boston'])
def test_graph_dijkstra_distance(benchmark, graph, source, target, expected_distance):
    """
    Find the shortest distance between two nodes in a graph using Dijkstra's algorithm.
    :param benchmark: benchmark fixture
    :param graph: city graph of the United States
    :param source: source city node
    :param target: target city node
    :param expected_distance: expected shortest distance (weight)
    """
    total_weight = benchmark(networkx.dijkstra_path_length, graph, source, target)
    assert total_weight == expected_distance
