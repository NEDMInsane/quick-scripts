#reading file parsing info

import os, re, pyperclip

actionRegex = re.compile (r'''(
    (\s|-|\.)? #beginning of bullet
    [a-zA-Z0-9._'!@#$%^&*()/ ]+ #whole action
    (\s|;|\.)? #end of action
    )''', re.VERBOSE)

resultRegex = re.compile (r'''(
    (\s|;|\.)? #start of result
    [a-zA-Z0-9._'!@#$%^&*()/ ]+ #whole result
    (\s|--|\.)? #end of result
    )''', re.VERBOSE)

impactRegex = re.compile (r'''(
    (\s|--|\.)? #start of impact
    [a-zA-Z0-9._'!@#$%^&*()/ ]+ #whole impact
    )''', re.VERBOSE)
#trying with pyperclip first
text = str(pyperclip.paste())
matches = []

##for groups in actionRegex.findall(text):
##    actionGrp = '*'.join([groups[1]])
##    matches.append(actionGrp)

##for groups in resultRegex.findall(text):
##    resultGrp = '&'.join([groups[1]])
##    matches.append(resultGrp)

for groups in impactRegex.findall(text):
    impactGrp = '^'.join([groups[0]])
    matches.append(impactGrp)

if len(matches) > 0:
    pyperclip.copy(str(matches))
    print('Copied to clipboard: ')
    print('\n'.join(matches))
else:
    print('No Bullets found.')
