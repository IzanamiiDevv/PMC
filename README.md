# PMC
Project Manager CLI: Help you to organize your Projects Directory


pmc -v
pmc -credits

pmc h
pmc help

pmc goto [projname]
pmc new [projname] -github
pmc new [projname] -local
pmc scan [status]
pmc del [projname]
pmc del finished

pmc mark [projname] -finished
pmc mark [projname] -ongoing > Set The Status

pmc code [projname] > Open VSCODE
pmc code > Open VSCODE with current project

single arg command:
    goto
    scan
    del
    code

multi arg command:
    new

status:
    finished > Project that is Done
    ongoing > Project that you working on
    unfinished > Project that has left due to new project was created


Gagawin ko bukas:

1.Fix Del Method to Log if Project is not yet Done
2.adjust some code
3.more


Todo:
    mark
    code
    scan -web
    new and create
    help and h
    -v
    -credits