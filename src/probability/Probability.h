#ifndef ASSIGNMENT6_PROBABILITY_H
#define ASSIGNMENT6_PROBABILITY_H

/**
 * @brief The Probability class encapsulates the probability of independent events. Where the likelihood of an event
 * ranges from 0.0 (never) to 1.0 (always).
 */
class Probability {
private:
    double _probability;

public:
    /**
     * @brief Constructs a Probability object from a double ranging from 0.0 to 1.0
     * @param p the probability of an independent event occuring ranging from 0.0 to 1.0
     * @throw std::invalid argument if p is outside of the range 0.0 <= p <= 1.0
     */
    explicit Probability(double p = 0.0);

    /**
     * @brief Converts a Probability object to a double
     * @return double representing the probability of an independent event
     */
    explicit operator double() const;

    /**
     * @brief Assigns a probability of an independent event represented as a double
     * @param p the probability of an independent event occuring ranging from 0.0 to 1.0
     * @return Probability object encapsulating the assigned probability
     * @throw std::invalid argument if p is outside of the range 0.0 <= p <= 1.0
     */
    Probability& operator= (double p);

    /**
     * @brief Tests two Probability objects for equality
     * @param p1 probability of event A
     * @param p2 probability of event B
     * @return true if the underlying probabilities are equal (A == B), false otherwise (A != B)
     */
    friend bool operator== (const Probability &p1, const Probability &p2);

    /**
     * @brief Computes the probability of an event not occurring
     * @details \f$ P = 1 - P_a \f$
     * @return Probability object representing the probability of an event not occurring
     */
    Probability operator~ () const;

    /**
     * @brief Computes the probability of events A and B occurring
     * @details \f$ P = P_a \cdot P_b \f$
     * @param p1 probability of event A
     * @param p2 probability of event B
     * @return Probability object representing the probability of two events occurring (A & B)
     */
    friend Probability operator& (const Probability &p1, const Probability &p2);

    /**
     * @brief Computes the probability of events A or B occurring
     * @details \f$ P = P_a + P_b - P_a \cdot P_b \f$
     * @param p1 probability of event A
     * @param p2 probability of event B
     * @return Probability object representing the probability of events A or B occurring (A | B)
     */
    friend Probability operator| (const Probability &p1, const Probability &p2);

    /**
     * @brief Computes the probability of events A or B but not both occurring
     * @details \f$ P = P_a + P_b - 2P_a \cdot P_b \f$
     * @param p1 probability of event A
     * @param p2 probability of event B
     * @return Probability object representing the probability of events A or B but not both occurring (A ^ B)
     */
    friend Probability operator^ (const Probability &p1, const Probability &p2);

    /**
     * @brief Computes the probability of event A but not B occurring
     * @details \f$ P = P_a - P_a \cdot P_b \f$
     * @param p1 probability of event A
     * @param p2 probability of event B
     * @return Probability object representing the probability of event A but not B occurring (A - B)
     */
    friend Probability operator- (const Probability &p1, const Probability &p2);

private:
    static double validateInput(double p);
};


#endif //ASSIGNMENT6_PROBABILITY_H
