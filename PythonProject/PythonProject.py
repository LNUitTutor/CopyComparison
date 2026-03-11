from figures import *
import copy

def printList(title, lst):
    print(title)
    for fig in lst:
        print(fig)
        print(f'  S = {fig.area()}   P = {fig.perimeter()}')

Origin = [ Circle(), Rectangle(), Circle(2.0), Rectangle(2.0, 1.0) ]
printList("--- The origin list of figures", Origin)
# Copy = Origin[:] 
Copy = copy.deepcopy(Origin)
for fig in Copy:
    fig.scalingBy(2.0)
printList("\n--- The copy after scaling by 2.0", Copy)
printList("\n--- The origin after scaling copy by 2.0", Origin)