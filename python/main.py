import cmd, sys
import os
from pathlib import Path
import readline
from LifeConsole import LifeConsole


class LifeConsoleCmd(cmd.Cmd, LifeConsole):
    intro = '祂有很多名字. 有人叫祂SuCicada. 有人叫祂蘇曉蝉\n'
    prompt = 'I  Say: '

    def precmd(self, line):
        return line

    def do_EOF(self, line):
        print("bye bye")
        return True

    completenames_ignore = ['EOF', 'help']

    def completenames(self, text, *args) -> list:
        res = super().completenames(text, args)
        return [a
                for a in res
                if a not in self.completenames_ignore]

    def cmdloop(self, *args):
        try:
            super().cmdloop()
        except KeyboardInterrupt:
            self.intro = " "
            self.cmdloop()

    def onecmd(self, line):
        command, arg, line = self.parseline(line)
        try:
            func = getattr(LifeConsole, command)
        except AttributeError:
            return super().onecmd(line)
        return func(arg)


HISTORY = f"{str(Path.home())}/.life-console-history"


def main():
    if not os.path.exists(HISTORY):
        open(HISTORY, 'w').close()

    readline.read_history_file(HISTORY)
    LifeConsoleCmd().cmdloop()
    readline.write_history_file(HISTORY)


if __name__ == '__main__':
    main()


def dev():
    cmd.Cmd.do_help
