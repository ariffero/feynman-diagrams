# feynman-diagrams
ROOT macros to draw some Feyman diagrams. The results are collected in the folder images.

1. **photonFusionLeptons.c** macro to produce the diagram of photon-photn fusion into two leptons at tree level. Landscape orientation. It has an option to draw the lepton with an arrow (default) or with a line, for the second execute the script using passing *false* as parameter.

2. **photonFusionX.c** macro to produce a diagram of photon-photon fusion into a generic state x. Interaction representat as a blob. Portrait orientation. It has an option to draw the final state with an arrow (default) or with a line, for the second execute the script using passing *false* as parameter.

3. **diffractive.c** macro that produces a diagram for a diffractive photon-nulcear interaction that produces a generic final state x. Interaction represented as a blob. Portrait orientation. It has an option to draw the final state with an arrow (default) or with a line, for the second execute the script using passing *false* as parameter.

4. **inclusive.c** macro that produces a diagram for an inclusive photon-nulcear interaction that produces a generic final state x. Interaction represented as a blob. Portrait orientation. It has an option to draw the final state products with arrows (default) or with lines, for the second execute the script using passing *false* as parameter.

5. **diffractiveEMD.c** macro that produces a diagram for a diffractive photon-nulcear interaction with EMD. It produces a generic state x plus a neutron in the final state. Photon-nuclear interaction represented as a blob. Portrait orientation. It has an option to draw the final state with an arrow (default) or with a line, for the second execute the script using passing *false* as parameter.

6. **VMPhotoprodEMD.c** macro that produced a diagram for a vector meson photoproduction in UPC accompained by EMD. It has an option to select the EMD type: Xn0n (EMD of one nucleus), XnXn (both nuclei undergo EMD). It has also another option to chose if use arrows or lines for the final state particles (arrows as default, lines passing *false* as second argument). The figure is in landscape orientation.
