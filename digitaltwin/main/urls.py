from django.urls import path
from . import views


urlpatterns = [
    path('', views.main),
    path('settings', views.settings),
    path('integration', views.integration),
]
