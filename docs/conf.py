import os, subprocess

project = 'math'
copyright = '2022-2024, Alfi Maulana'
author = 'Alfi Maulana'

extensions = ['breathe']

dir_path = os.path.dirname(os.path.realpath(__file__))
subprocess.call('cd %s && doxygen' % dir_path, shell=True)

breathe_projects = {"math": "_xml"}
breathe_default_project = "math"

html_theme = 'sphinx_rtd_theme'
html_static_path = ['_static']
