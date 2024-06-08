import matplotlib.pyplot as plt
import networkx
import pytest

from algorithm.graph.test.graph_data_utils import create_weighted_city_graph

city_graph = create_weighted_city_graph()


@pytest.mark.skip(reason='This test is for visualization only')
def test_graph_mst_temp():
    mst = networkx.minimum_spanning_tree(city_graph, algorithm='kruskal')
    pos = networkx.spring_layout(mst)
    networkx.draw_networkx_nodes(mst, pos)
    networkx.draw_networkx_edges(mst, pos, width=1)
    networkx.draw_networkx_labels(mst, pos, font_size=10)
    plt.show()


city_edges = {('Seattle', 'San Francisco'), ('San Francisco', 'Los Angeles'), ('Los Angeles', 'Riverside'),
              ('Riverside', 'Phoenix'), ('Phoenix', 'Dallas'), ('Dallas', 'Houston'), ('Houston', 'Atlanta'),
              ('Atlanta', 'Miami'), ('Atlanta', 'Washington'), ('Washington', 'Philadelphia'),
              ('Philadelphia', 'New York'), ('New York', 'Boston'), ('Washington', 'Detroit'), ('Detroit', 'Chicago')}


@pytest.mark.benchmark(group='graph_minimum_spanning_tree')
@pytest.mark.parametrize(
    argnames='graph, algorithm, expected_total_weight, expected_edges',
    argvalues=[
        (city_graph, 'kruskal', 5372, city_edges),
        (city_graph, 'prim', 5372, city_edges),
        (city_graph, 'boruvka', 5372, city_edges),
    ],
    ids=['kruskal', 'prim', 'boruvka'])
def test_graph_mst(benchmark, graph, algorithm, expected_total_weight, expected_edges):
    mst = benchmark(networkx.minimum_spanning_tree, graph, algorithm=algorithm)

    mst_total_weight = sum(d['weight'] for u, v, d in mst.edges(data=True))
    assert expected_total_weight == mst_total_weight

    mst_edges = set((u, v) for u, v, d in mst.edges(data=True))
    normalized_set1 = {tuple(sorted(edge)) for edge in expected_edges}
    normalized_set2 = {tuple(sorted(edge)) for edge in mst_edges}
    assert normalized_set1 == normalized_set2
