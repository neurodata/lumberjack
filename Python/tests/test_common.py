import pytest

from sklearn.utils.estimator_checks import check_estimator

from rerfClassifier import rerfClassifier


@pytest.mark.parametrize("Estimator", [rerfClassifier])
def test_all_estimators(Estimator):
    return check_estimator(Estimator)
