import pydevd_pycharm

pydevd_pycharm.settrace('win.ip', port=1234, stdoutToServer=True, stderrToServer=True)

import main
main.main()
